# A. Three Indices
t=int(input())
for j in range(t):
        n=int(input())
        p=list(map(int,input().split()))
        flag=0
        for i in range(n-2):
            if p[i]<p[i+1] and p[i+1]>p[i+2]:
                print("YES")
                print(i+1,i+2,i+3)
                flag=1
                break
        if flag==0:
            print("NO")

            