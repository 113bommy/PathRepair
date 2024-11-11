N = int(input())
words = []
for _ in range(N):
    words.append(input())
print('Yes' if all(words[i].startswith(words[i-1][-1]) for i in range(1, N)) and len(set(words)) == N else 'No')