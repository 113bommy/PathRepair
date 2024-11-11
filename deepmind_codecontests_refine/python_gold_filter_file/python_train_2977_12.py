import sys
import collections

def main():
    n,k = map(int, sys.stdin.readline().split())

    ans = []

    i = 2
    aux = n
    while i*i <= n:
        while(k > 1 and aux%i == 0):
            aux //= i
            ans.append(i)
            k -= 1
        i += 1

    if(k > 1 or aux == 1): print(-1)
    else:
        ans.append(aux)
        for i in ans:
            print(str(i), end=" ")


if __name__ == "__main__":
    main()