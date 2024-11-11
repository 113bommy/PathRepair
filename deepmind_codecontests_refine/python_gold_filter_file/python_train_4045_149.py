S = input().strip()
print('yes' if len(S) == len(set(S)) else 'no')