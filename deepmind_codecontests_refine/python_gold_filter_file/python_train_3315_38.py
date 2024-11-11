A, B = map(int, input().split())
print('Impossible' if A % 3 and B % 3 and (A + B) % 3 else 'Possible')
