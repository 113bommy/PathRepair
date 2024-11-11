t=int(input())
for _ in range(t):
    n=int(input())
    arr= list(map(int,input().split()))
    ans=[]
    arr.sort()
    if (n%2==0):
        ans.append(arr[int(n/2)-1])
        ans.append(arr[int(n/2)])
        for i in range(1,int(n/2)):
            ans.append(arr[int(n/2)-i-1])
            ans.append(arr[int(n/2)+i])
    else:
        ans.append(arr[int(n/2)])
        for i in range(1,int(n/2)+1):
            ans.append(arr[int(n/2)-i])
            ans.append(arr[int(n/2)+i])
    
    print(*ans,sep=" ")





# t=int(input())
# for _ in range(t):
#     n=int(input())
#     arr=list(map(int,input().split()))
#     c=0
#     s=[0]*(n-1)
#     arr.sort()
#     ans=[]
#     for i in range(1,n):
#         s[i-1]=abs(arr[i]-arr[i-1])
#     # print(s)
#     ans.append(arr[s.index(min(s))])
#     ans.append(arr[(s.index(min(s)))+1])
#     print(arr)
#     arr.pop(arr.index(ans[0]))
#     arr.pop(arr.index(ans[1]))
#     print(arr)
#     i=n-len(ans)
#     while i>0:
#         mi=float("inf")
#         for j in arr:
#             if abs(ans[len(ans)-1]-j)<=mi:
#                 e=j
#                 mi =  abs(ans[len(ans)-1]-j)
#         ans.append(e)
#         arr.pop(arr.index(e))
#         i-=1
#     print(*ans,sep=" ")
        
            
        

# # t=int(input())
# # for _ in range(t):
# #     n=int(input())
# #     arr=list(map(int,input().split()))
# #     c=0
# #     s=[]
# #     for i in range(n):
# #         e1=-1
# #         e2=-1
# #         i-=c
# #         mi=float("inf")
# #         for j in range(i+1,len(arr)):
# #             print(i,j)
# #             if i==j:
# #                 continue
# #             else:
# #                 # print(arr[i]-arr[j],mi)
# #                 if abs(arr[i]-arr[j])<=mi:
# #                     mi=abs(arr[i]-arr[j])
# #                     e1=arr[i]
# #                     e2=arr[j]
# #                 # print('mi',mi)
# #         print(arr,e1,e2,s,mi)
# #         arr.pop(arr.index(e1))
# #         arr.pop(arr.index(e2))
# #         c+=2
# #         s.append(e1)
# #         s.append(e2)
# #     print(s)

            
        