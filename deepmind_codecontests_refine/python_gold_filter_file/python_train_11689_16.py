n = int(input())
a1, b1, c1 = map(int, input().split())
a2, b2, c2 = map(int, input().split())
mx = min(a1, b2) + min(b1, c2) + min(c1, a2)
mxb = min(a2, b1) + min(b2, c1) + min(c2, a1)
#if max(a2, b2, c2) == a2:
mn1 = a2 - a1 - b1
#elif max(a2, b2, c2) == b2:
mn2 = b2 - c1 - b1
#elif max(a2, b2, c2) == c2:
mn3 = c2 - a1 - c1
#print(mn1, mn2, mn3)
print(max(0, mn1, mn2, mn3), mx)
