As = list(map(int, input().split()))
print('bust' if sum(As) > 21 else 'win')