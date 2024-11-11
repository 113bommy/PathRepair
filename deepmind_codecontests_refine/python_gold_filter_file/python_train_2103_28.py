# str = input()
# # str = str.upper()
# lst_lower = []
# lst_upper = []
# for i in str:
#     # print(i)
#     if i == i.upper():
#         lst_upper.append(i)
#     if i == i.lower():
#         lst_lower.append(i)
# # print(str)
# # print(len(lst_lower))
# # print(len(lst_upper))
# # print(lst_upper)
# if len(lst_lower) < len(lst_upper):
#     str = str.upper()
# elif len(lst_lower) > len(lst_upper):
#     str = str.lower()
# else:
#     str = str.lower()
# print(str)


t = int(input())
s = 0
q = 0
for i in range(t):
    a, b, c, d, k = map(int, input().split())
    # print("a:",a," b:",b," c:",c," d:",d)
    if a > c:
        # s = 0
        # while a // c != 0:
        #     a = a // c
        #     s += 1
        if a % c == 0:
            s = (a // c)
        else:
            s = (a // c) + 1
        # print("s:", s)
    elif a <= c:
        s = 1
        # print("s:", 1)
    if b > d:
        if b % d == 0:
            q = (b // d)
        else:
            q = (b // d) + 1
        # print("q:", q)
    elif b <= d:
        q = 1
        # print("q:", 1)
    # print("s:", s, "q:", q)
    if s + q <= k:
        print(s, q)
    else:
        print(-1)

#
# n = int(input())
# s = int(input())
# counter = 0
# while n % s != 0:
#     # print(n % s)
#     n = n // s
#     # print(n)
#     counter += 1
# print(counter-1)
