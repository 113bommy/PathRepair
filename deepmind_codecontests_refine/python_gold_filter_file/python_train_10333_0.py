from sys import exit
from traceback import format_exc

def main():
    n = int(input())
    if n < 4:
        print(0, flush=True)
        return
    on = [False] * n
    def query(ll):
        res = 0
        pvals = [i+1 for i in ll]
        print(len(ll), *pvals, flush=True)
        for i in ll:
            if not on[i]:
                res += 1
                on[i] = True
        x = int(input())
        if x == -1:
            exit()
        for i in range(x-1, x+len(ll)-1):
            if on[i%n]:
                res -= 1
                on[i%n] = False
        return res

    k = min(range(2, n), key = lambda k: k + (n-1)//k)
    blocked = [i%k == 0 for i in range(n)]
    while True:
        ll = []
        count = 0
        for i in range(n):
            if not on[i] and not blocked[i]:
                ll.append(i)
                count+=1
                if count == k:
                    break
        res = query(ll)
        if res < 1:
            break

    print(0, flush=True)

if __name__ == "__main__":
    try:
        main()
    except:
        print(format_exc())