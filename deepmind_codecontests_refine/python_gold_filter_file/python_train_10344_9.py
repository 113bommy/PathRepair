# l = [list(map(int,input().split())) for i in range(3)]
# l1 = [[1,1,1],[1,1,1],[1,1,1]]
# for i in range(3):
#     for j in range(3):
#         l[i][j]%=2
# for i in range(3):
#     for j in range(3):
#         if l[i][j] == 1:
#             for y in range(0,3):
#                 if l1[y][j] == 1:
#                     l1[y][j] = 0
#                 else:
#                     l1[y][j] = 1
#             print('y')
#             for _ in range(3):
#                 print(l1[_])
#             for x in range(0,3):
#                 # print(x,j)
#                 if x == j:
#                     continue
#                 else:
#                     if l1[i][x] == 1:
#                         l1[i][x] = 0
#                     else:
#                         l1[i][x] = 1
#             print('x')
#             for _ in range(3):
#                 print(l1[_])
# for i in range(3):
#     print(l1[i])


n = int(input())
l = list(map(int,input().split()))
m = int(input())
l2 = list(map(int,input().split()))

dict = {}

for i in range(n):
    dict[l[i]] = i
a = 0
b = 0
for i in range(m):
    index = dict[l2[i]]
    a+= index +1
    b+= n - index
print(a,b)
