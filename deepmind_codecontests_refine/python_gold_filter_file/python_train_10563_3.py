n, m = map(int, input().split())
words = []
for _ in range(m):
    words.append(input())
sentence = input().split()
lang1, lang2 = [], []
for word in words:
    for i in range(len(word)):
        if word[i] == ' ':
            lang1.append(word[:i])
            lang2.append(word[i+1:])
            break
to_speak = ''
for w in sentence:
    idx = lang1.index(w)
    to_speak += f'{[w, lang2[idx]][len(lang2[idx]) < len(w)]} '
print(to_speak)