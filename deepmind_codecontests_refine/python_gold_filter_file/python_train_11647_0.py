S = input()
for i in range(1, len(S)):
    if S[i] == S[i-1]: print(i, i+1); break;
    if i > 1 and S[i] == S[i-2]: print(i-1, i+1); break;
else:
    print(-1, -1)