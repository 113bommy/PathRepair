numFeet = int(input())
arr = list(map(int,input().split()))
stack = []
r_arr = [numFeet] * (numFeet+1)
l_arr = [-1] * (numFeet+1)
ans = [0]*(numFeet+1)

for i in range(numFeet):
    while stack and arr[stack[-1]] >= arr[i]:
        stack.pop()
    if stack:
        l_arr[i] = stack[-1]
    stack.append(i)
# get rid of everything in stack
while stack:
    stack.pop()
for i in range(numFeet-1, -1, -1):
    while stack and arr[stack[-1]] >= arr[i]:
        stack.pop()
    if stack:
        r_arr[i] = stack[-1]
    stack.append(i)
for i in range(numFeet):
    temp = r_arr[i]-l_arr[i]-1
    ans[temp] = max(arr[i],ans[temp])
for i in range(numFeet-1, -1, -1):
    ans[i] = max( ans[i+1],ans[i])
for x in ans[1:]:
    print(x ,end=" ")
