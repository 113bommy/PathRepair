'''Author- Akshit Monga'''
import sys
# input=sys.stdin.readline
t = int(input())
for _ in range(t):
    n=int(input())
    a=input()
    b=input()
    var=0
    ans=[]
    for i in range(n):
        if a[i]==b[i]:
            continue
        ans.append(i+1)
        ans.append(1)
        ans.append(i+1)
        var+=3
    print(var,end=" ")
    for i in ans:
        print(i,end=" ")
    print()