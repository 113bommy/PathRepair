m = [int(x) for x in input().split()]
a = m[0] * m[1] + 2 * m[3]
b = m[0] * m[2] + 2 * m[4]
if a < b:
    print("First")
elif a > b:
    print("Second")
elif a == b:
    print("Friendship")