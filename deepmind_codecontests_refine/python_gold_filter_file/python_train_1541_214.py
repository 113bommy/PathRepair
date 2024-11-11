l=list(map(int,input().split()))
print('bust' if sum(l)>21 else 'win')