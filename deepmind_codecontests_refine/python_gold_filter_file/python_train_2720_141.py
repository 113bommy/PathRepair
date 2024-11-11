# # RED CODER # #
# t = int(input())
# for items in range(t):
#     l1, r1, l2, r2 = map(int, input().split())
#     print(r1, l1)
x = int(input())
n = x % 4
if n == 0 or n == 3:
    print(0)
if n == 1 or n ==2:
    print(1)