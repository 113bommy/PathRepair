a, b = map(int, input().split())
c = input()
print(c[0:b-1]+c[b-1].lower()+c[b:])
