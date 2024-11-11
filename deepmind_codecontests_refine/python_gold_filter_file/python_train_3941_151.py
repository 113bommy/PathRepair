A,B,C = map(int, input().split())
print('YNeos'[not(A<=C<=B)::2])