def check(x,y):
    if(x%2==0):
        if (y in range(x//2)):
            return True
        return False
    if (y in range(x //2+1)):
        return True
    return False


def solve(n,x):
    se=set()
    unused=[]
    for i in x:
        if(i>n) or (i in se):
            unused.append(i)
        else:
            se.add(i)
    wanted=[]
    for i in range(1,n+1):
        if(i not in se):
            wanted.append(i)
    unused.sort()
    for i in range(len(unused)):
        if(not check(unused[i],wanted[i])):
            return -1
    return len(unused)




t=int(input())
for _ in range(t):
    n=int(input())
    x=list(map(int,input().strip().split()))
    print(solve(n,x))
