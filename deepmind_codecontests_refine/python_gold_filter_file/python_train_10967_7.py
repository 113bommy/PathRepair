#616A
# a = input()
# b = input()
# a = a.lstrip("0")
# b = b.lstrip("0")
# if len(str(a)) == 0:
#     a = 0
# if len(str(b))  == 0:
#     b = 0
# a = int(a)
# b = int(b)
# if a>b:
#     print(">")
# elif a<b:
#     print("<")
# else:
#     print("=")

#118A
# vowels = ['a', 'e', 'i', 'o', 'u']
# s = [i.lower() for i in input()]
# result = []
# for i in range(len(s)):
#     if s[i] in vowels:
#         result.append("")
#     else:
#         result.append(".")
#         result.append(s[i])
# print(''.join(result))

#1293B
# n = int(input())
# ans = sum([1.0 / i for i in range(1, n+1)])
# print(ans)

#761A
# x,y = input().split()
# x = int(x)
# y = int(y)
# if x==0 and y==0:
#     print("NO")
# elif abs(x-y) <= 1:
#     print("YES")
# else:
#     print("NO")

#864A
# n = int(input())
# a = []
# d = []
# j = 0
# for i in range(n):
#     k = int(input())
#     a.append(k)
#     if k not in d:
#         d.append(k)
#         j = j + 1
# q = 0
# w = 0
# if j != 2:
#     print("NO")
# else:
#     z = d[0]
#     x = d[1]
#     for i in range(n):
#         if a[i] == z:
#             q = q + 1
#         if a[i] == x:
#             w = w + 1
#     if w != q:
#         print("NO")
#     else:
#         print("YES")
#         print(d[0], d[1])

#616B
# n, m = input().split()
# n = int(n)
# m = int(m)
# arr = [[i for i in input().split()][:m] for y in range(n)]
# max = -100000
# for i in range(n):
#    mini = min(arr[i])
#    if int(mini) > int(max):
#        max = mini
# print(max)

#284B
# n = int(input())
# a = [i for i in input()][:n]
# j = 0
# na = 0
# ni = 0
# nf = 0
# for i in range(n):
#     if a[i] == 'A':
#         na = na + 1
#     elif a[i] == 'I':
#         ni = ni + 1
#     else:
#         nf = nf + 1
# for i in range(n):
#     if a[i] == 'A':
#         if ni == 0:
#             j = j + 1
#     elif a[i] == 'I':
#         if ni == 1:
#             j = j + 1
#     else:
#         pass
# print(j)

#82A
# names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
# n = int(input())
# r = 1
# while r * 5 < n:
#     n = n - (r*5)
#     r = r * 2
# k = int((n-1)/r)
# print(names[k])

#Youtube Class
# class Employee:
#     def __init__(self, first, last):
#         self.first = first
#         self.last = last
#     def fullname(self):
#         return self.first + " " + self.last
#
# emp1 = Employee("rose", "rouhani")
# print(emp1.fullname())

#1176B
# import math
# n = input()
# n = int(n)
# b = [[0 for x in range(0)] for y in range(n)]
# for i in range(n):
#     a = int(input())
#     f = [(int(j)%3) for j in input().split()][:a]
#     b[i]= f
# for i in range(n):
#     t = 0
#     z = 0
#     one = 0
#     two = 0
#     for j in range(len(b[i])):
#         if b[i][j] == 0:
#             z = z + 1
#         elif b[i][j] == 1:
#             one = one + 1
#         else:
#             two = two + 1
#     t = z
#     if one == two:
#         t = t + (one)
#     else:
#         m = min(one, two)
#         t = t + ( m + (one + two - 2 * m) / 3 )
#     print(math.floor(t))


#785B
# infinity = 1234567890
# minR1 = minR2 = infinity
# maxL1 = maxL2 = -infinity
# n = int(input())
# for i in range(0, n):
# 	(l, r) = map(int, input().split())
# 	maxL1 = max(maxL1, l)
# 	minR1 = min(minR1, r)
# m = int(input())
# for i in range(0, m):
# 	(l, r) = map(int, input().split())
# 	maxL2 = max(maxL2, l)
# 	minR2 = min(minR2, r)
# res = max(maxL2 - minR1, maxL1 - minR2)
# print(max(res, 0))


#495A i dont get it?
# v = [2, 7, 2, 3, 3, 4, 2, 5, 1, 2]
# n = int(input())
# print(v[int(n/10)] * v[int(n % 10)])

#792A
# n = int(input())
# f = [int(i) for i in input().split()][:n]
# m = 123445678980
# q = 0
# f.sort()
# # print(f)
# for i in range(n-1):
#     k = min(abs(f[i] - f[i+1]), abs(f[i] - f[i-1]))
#     m = min(m, k)
# for i in range(n-1):
#     if abs(f[i] - f[i+1]) == m:
#         q += 1
# print(m, q)

#218A
n, m = map(int, (input().split()))
a = [int(i) for i in input().split()][:2*n+1]
# print(a)
j = 0
for i in range(2*n+1):
    if a[i] > 0 and a[i] > a[i-1] + 1 and a[i] > a[i+1] + 1:
        a[i] = a[i] - 1
        j += 1
        # print(a[i])
    if j == m:
        break
print(*a, sep=" ")