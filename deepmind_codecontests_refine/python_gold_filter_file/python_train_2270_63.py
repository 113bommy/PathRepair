a, b = map(int, input().split())
t = input()
print(t[:b-1] + t[b-1].lower() + t[b:])