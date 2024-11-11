t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    m={}
    # o={}
    o=[]
    f=0
    for i in range(n):
        m[i]=(i+(arr[i]))%n
        # o[i]=arr[i]
        if m[i] in o:
            f=1
            break
        else:
            o.append(m[i])
    if f:
        print("NO")
    else:
        print("YES")




# t=int(input())
# for _ in range(t):
#     n=int(input())
#     arr=list(map(int,input().split()))
#     m={}
#     o={}
#     f=0
#     for i in range(n):
#         m[i]=i+(arr[i]%n)
#         o[i]=arr[i]
#         # print(i+(arr[i]%n),arr[i])
#         # if i+(arr[i]%n) == arr[i]:
#         # m[i]=i+(arr[i]%n) == arr[i]
#             # print("HERE")
#             # break
#         # else:
#             # f+=1
#     # print(m)
#     for i in range(n):
#         if m[i]==o[i]:
#             f=1
#             break
#     print(m,o)
#     if f:
#         print("NO")
#     else:
#         print("YES")
