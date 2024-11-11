n=int(input())
arr=list(map(int,input().split()))
stack=[]
left=[0 for i in range(n)]
right=[0 for i in range(n)]
for i in range(n):
    while stack and arr[i] <= arr[stack[-1]]:
        stack.pop()
    left[i]=i-stack[-1]-1 if stack else i
    stack.append(i)
stack=[]
for i in range(n-1,-1,-1):
    while stack and arr[i] <= arr[stack[-1]]:
        stack.pop()
    right[i]=stack[-1] -i if stack else n-i
    stack.append(i)
ans=[0 for i in range(n+1)]
for i in range(n):
    ans[left[i]+right[i]]=max(ans[left[i]+right[i]],arr[i])
for i in range(n-1,0,-1):
    ans[i]=max(ans[i],ans[i+1])
mini=9999999999999
for i in range(1,n+1):
    if ans[i]==0:
        print(mini,end=' ')
    else:
        print(ans[i],end=' ')
        mini=ans[i]
print()