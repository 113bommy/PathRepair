########################################

#            SUBTRACTIONS              #

########################################

# for _ in range(int(input())):
#     a, b = map(int, input().split())
#     c = 0
#     while(min(a, b) != 0):
#         ma = max(a, b)
#         mi = min(a, b)
#         a = mi
#         b = ma
#         c += b//a
#         b = b % a
#     print(c)

########################################

#             CANDIES                 #

########################################

# from math import log2, floor, ceil
# for _ in range(int(input())):
#     a = int(input())
#     c = ceil(log2(a))
#     # print(c)
#     for i in range(c, 0, -1):
#         if((a//((2**i)-1)) == ceil(a/((2**i)-1))):
#             print((a//((2**i)-1)))
#             break

########################################

#         VASYA AND SOCKS              #

########################################

# a, b = map(int, input().split())
# c = (a-1)//(b-1)
# print(a+c)

########################################

#       MULTIPLY BY 2, DIVIDE BY 6     #

########################################

# for _ in range(int(input())):
#     n = int(input())
#     if(n == 1):
#         print(0)
#     else:
#         op = 0
#         while(True):
#             if(n % 6 == 0):
#                 n = n//6
#                 op += 1
#             elif((n-3) % 6 == 0):
#                 n = (n*2)//6
#                 op += 2
#             else:
#                 op = -1
#                 break
#             if(n == 1):
#                 break
#         print(op)

########################################

#      Kana and Dragon Quest game      #

########################################

# for _ in range(int(input())):
#     h, n, m = map(int, input().split())
#     if((h-(m*10)) <= 0):
#         print("YES")
#     else:
#         for i in range(n):
#             if(h <= 0):
#                 print("YES")
#                 break
#             h = (h//2)+10
#         if(h > 0):
#             if((h-(m*10)) <= 0):
#                 print("YES")
#             else:
#                 print("NO")

########################################

#      rice bag a+B waala              #

########################################

# for _ in range(int(input())):
#     # print(int(input()))
#     n, a, b, c, d = map(int, input().split())
#     if(n*(a-b) > (c+d) or n*(a+b) < (c-d)):
#         print("NO")
#     else:
#         print("YES")

########################################

#              FOOD BUYING             #

########################################

# for _ in range(int(input())):
#     a = int(input())
#     b = 0
#     while(a >= 10):
#         b = b+((a//10)*10)
#         a = (a % 10)+(a//10)

#     print(a+b)

########################################

#           Avoiding Zeroes            #

########################################

# for _ in range(int(input())):
#     a = int(input())
#     arr = list(map(int, input().split()))

#     b = 0
#     c = ""
#     sn = 0
#     sp = 0
#     for i in range(a):
#         b += arr[i]
#         if(arr[i] > 0):
#             sp += arr[i]
#         elif(arr[i] < 0):
#             sn += abs(arr[i])
#         if(arr[i] == 0):
#             c += " 0"
#     if(sn > sp):
#         ar = sorted(arr)
#     elif(sp > sn):
#         ar = sorted(arr, reverse=True)
#     if(b != 0):
#         print("YES\n")
#         print(" ".join(str(x) for x in ar if x != 0), end='')
#         print(c)
#     else:
#         print("NO")

########################################

#             FOOTBALL                 #

########################################

# s = input()
# if('0000000' in s or '1111111' in s):
#     print("YES")
# else:
#     print("NO")

########################################

#               TWINS                  #

########################################

# n = int(input())
# arr = list(map(int, input().split()))
# s = sum(arr)
# c = su = 0
# for i in range(n):
#     for j in range(n-i-1):
#         if(arr[j] > arr[j+1]):
#             arr[j], arr[j+1] = arr[j+1], arr[j]
#     su += arr[-1-i]
#     c += 1
#     if(su > (s-su)):
#         break
# print(c)

########################################

#            cAPS LOCK                 #

########################################

# s = input()
# a = str(s[0].upper())+s[1:].lower()
# if(s.upper() == s):
#     print(s.lower())
# elif(a[1:].upper() == s[1:]):
#     print(a)
# else:
#     print(s)

########################################

#            DUBSTEPS                  #

########################################

# s = list(map(str, input().split("WUB")))
# print(" ".join(s))

# print(*input().split("WUB"))

########################################

#        anton and polyhedrons         #

########################################

# a = {"Tetrahedron": 4, "Cube": 6, "Octahedron": 8,
#      "Dodecahedron": 12, "Icosahedron": 20}
# s = 0
# for i in range(int(input())):
#     s += a[input()]
# print(s)

########################################

#            Move Brackets             #

########################################

# for _ in range(int(input())):
# a = input()
# s = input()
# cc = 0
# c = 0
# for i in s:
#     if(i == ')'):
#         cc += 1
#     else:
#         cc -= 1
#     if(i == ')' and cc > 0):
#         c += 1
#         cc = 0
# print(c)

########################################

#              Chat Room               #

########################################

# s = input()
# st = "hello"
# a = -1
# for i in s:
#     if(st[a+1] == i):
#         a += 1
#     if(a == 4):
#         break
# if(a < 4):
#     print("NO")
# else:
#     print("YES")

########################################

#            TWO SUBSTRING             #

########################################

# def find(s, l):
#     a = ''
#     for i in range(0, l, 2):
#         a = s[i:i+2]
#         a = a[::-1]
#         if(a in s and len(a) == 2):
#             return True
#     for i in range(1, l, 2):
#         a = s[i:i+2]
#         a = a[-1:]
#         if(a in s and len(a) == 2):
#             return True
#     return False

# a = input()
# l = len(a)
# f = 0
# if(l <= 3):
#     print("NO")
# else:
#     s = a
#     if("AB" in s):
#         s = s.replace("AB", " ", 1)
#         if("BA" in s):
#             print("YES")
#             f = 1
#         # print(s)
#     s = a
#     if("BA" in s and f == 0):
#         s = s.replace("BA", " ", 1)
#         if("AB" in s):
#             print("YES")
#             f = 1
#     if(f == 0):
#         print("NO")

########################################

#               LECTURE                #

########################################

a = {}
n, m = map(int, input().split())
for i in range(m):
    x, y = map(str, input().split())
    if(len(x) > len(y)):
        a[x] = y
    else:
        a[x] = x
b = [str(x) for x in input().split()]
for j in b:
    print(a[j], end=" ")
print("\n")
