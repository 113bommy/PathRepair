n=int(input())
arr=list(map(int,input().split()))
arr2=[]
s=0
for i in range(0,len(arr)):
   s=s+arr[i]
   arr2.append(s) 
# print(arr2)
arr1=[]
T=int(input())
for i in range(0,T):
    x,y=map(int,input().split())
    if x==1:
        # print(arr2[x-1])
        print(arr2[y-1]//10)
    else:
        print((arr2[y-1]-arr2[x-2])//10)