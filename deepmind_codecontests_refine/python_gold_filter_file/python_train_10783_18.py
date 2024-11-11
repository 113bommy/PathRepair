from sys import stdin, stdout


n, m = map(int, stdin.readline().rstrip().split())

def triangle(x):
    return x*(x+1)//2

if n<=m:
    print(n)
else:
    target=n-m # Want to find the triangle number which is greater than the target
    minNum=0
    maxNum=int(1e10)
    finished=False
    while not finished:
        newNum = (minNum+maxNum)//2
        if triangle(newNum)<target and triangle(newNum+1)>=target:
            finished=True
        elif triangle(newNum)<target:
            minNum=newNum
        elif triangle(newNum)>=target and triangle(newNum-1)<target:
            finished=True
            newNum-=1
        else:
            maxNum=newNum
    print(m+newNum+1)
