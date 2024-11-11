'''
tìm vị trí sớm nhất mà lượng mưa nhỏ hơn x ngày trước và y ngày sau
'''
n,x,y=map(int,input().split(' '))
rainingday=list(map(int,input().split(' ')))
stack=[0]
left=[0 for i in range(n)]
right=[n-1 for i in range(n)]

for i in range(1,n):
    while(len(stack)!=0 and rainingday[stack[-1]]>=rainingday[i]):
        right[stack[-1]]=i-1
        stack.pop()
    if(len(stack)!=0):
        left[i]=stack[-1]+1
    else:
        left[i]=0
    stack.append(i)



for i in range(n):
    if(i-left[i]>=x and right[i]-i>=y):
        print(i+1)
        break
    elif((left[i]==0 or i-left[i]>=x) and (right[i]==n-1 or right[i]-i>=y)):
        print(i+1)
        break

