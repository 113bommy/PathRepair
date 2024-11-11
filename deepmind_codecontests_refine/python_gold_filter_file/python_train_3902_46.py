n,m=map(int,input().split())
odd=[]
even=[]
even2=[]
for i in range(m-1):
    odd+="#"
    even+="."
odd+="#"
even+="#"
even2+="#"
for i in range(m-1):
    even2+="."
for i in range(n):
    if i%2==0:
        for j in range(m):
            print(odd[j],end="")
    elif i%4==1:
        for j in range(m):
            print(even[j],end="")
    else:
        for j in range(m):
            print(even2[j],end="")
    print()