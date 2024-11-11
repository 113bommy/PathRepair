n = map(int, input().split())
print('bust' if sum(n) >= 22 else 'win')