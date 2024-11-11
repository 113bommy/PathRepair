n=int(input())
li=list(map(int,input().split()))
se=list(set(li))
se.sort()
if len(se)==1:
    print("NO")
else:
    print(se[1])