n=int(input())

l=list(map(int,input().split()))
for j in l:
    if j%14>0 and j%14<7 and j>14:
        print("YES")
    else:
        print("NO")
