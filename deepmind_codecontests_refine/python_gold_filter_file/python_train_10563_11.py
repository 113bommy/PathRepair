
n, m = list(map(int, input().split(' ')))

a = dict()
b = dict()

for i in range(m):
    tmp_words = input()
    tmp_a, tmp_b = tmp_words.split(' ')
    a[tmp_a] = tmp_b
    b[tmp_b] = tmp_a

result = ""
for word in input().split(' '):
    if word in a:
        result += len(word) <= len(a[word]) and word or a[word]
    else:
        result += len(word) < len(b[word]) and word or b[word]
    result += " "
print(result)





