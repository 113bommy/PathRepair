from sys import setrecursionlimit
setrecursionlimit(1000000000)

def main():
    a, b, c=[int(i) for i in input().split()]
    if c%a==0:
        print("-1")
        return 0
    p=c//a
    if p==0:
        if (b>-1*a/2) and (b<a/2):
            print('1')
            return 0
    elif p%2==0:
        if (b > -1*a) and (b<0):
            print(p//2*3)
            return 0
        if (b<a) and (b>0):
            print(p//2*3+1)
            return 0
    else:
        if (b>-1*a/2) and (b<a/2):
            print(p//2*3+2)
            return 0
    print("-1")

main()

