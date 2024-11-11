S = input()

print("Yes" if ('L' not in S[0::2] and 'R' not in S[1::2]) else "No")