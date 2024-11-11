n=int(input())
for i in range(n):
    s=input()
    t=input()
    if len(set(s)&set(t))>0:
        print("YES")
    else:
        print("NO")
