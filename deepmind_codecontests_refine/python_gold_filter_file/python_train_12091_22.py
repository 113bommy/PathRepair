n, m, k = map(int, input().split())
emotes = list(map(int, input().split()))
emotes.sort(reverse=True)

res = emotes[0] * (m // (k + 1)) * k + emotes[1] * (m // (k + 1)) + (m % (k + 1)) * emotes[0]
print(res)
