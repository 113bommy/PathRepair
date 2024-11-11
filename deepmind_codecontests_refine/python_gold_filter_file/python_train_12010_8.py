n=int(input())
r=list(set(list(map(int,input().split()))))

r.sort()

if len(r)==1:
    print("NO")
else:
    print(r[1])