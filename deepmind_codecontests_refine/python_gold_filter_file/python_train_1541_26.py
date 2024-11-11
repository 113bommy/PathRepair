d=list(map(int, input().split()))
print('bust' if sum(d)>21 else 'win')