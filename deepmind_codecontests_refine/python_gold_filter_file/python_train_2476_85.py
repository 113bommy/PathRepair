a, b, c, d = map(int, input().split())
if -(-a//d) < -(-c//b):
    print("No")
else:
    print("Yes")