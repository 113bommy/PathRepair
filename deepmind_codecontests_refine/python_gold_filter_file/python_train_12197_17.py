n = int(input())
i = 5
if n < 25:
    print(-1)
    exit()
while n % i != 0:
    i += 1
if i == n or n//i < 5:
    print(-1)
    exit()
vowel = 'aeiou'
final = ''
for j in range(n//i):
    temp = vowel*(i//5) + vowel[:i%5]
    vowel = vowel[1:] + vowel[0]
    final += temp
print(final)