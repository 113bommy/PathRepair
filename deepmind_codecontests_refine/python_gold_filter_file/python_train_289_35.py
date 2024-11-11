S=input()
for i in range(8):
    if S[:i]+S[len(S)-7+i:] == 'keyence':
        print('YES')
        exit()
print('NO')
