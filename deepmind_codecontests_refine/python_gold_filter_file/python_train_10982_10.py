#!/bin/python
def splt(a):
    answer = []
    for i in range(2, a+1):
        if a%i == 0:
            while a%i == 0:
                answer.append(i)
                a=a/i
        if a == 1:
            break
    return answer

def main():
    n = int(input())
    sets = []
    ans = []
    for a in range(2, n+1):
        spl = splt(a)
        enuf = 1
        for b in spl:
            if spl.count(b) > sets.count(b):
                enuf = 0
                for c in range(spl.count(b)-sets.count(b)):
                    sets.append(b)
        if enuf == 0:
            ans.append(str(a))
    print(len(ans))
    print(' '.join(ans))

if __name__ == "__main__":
    main()
