import sys

string = sys.stdin.readline().strip()
last_symbol = '`'
answer = True

for letter in string:
    if ord(letter) - ord(last_symbol) > 1:
        answer = False
        break
    if letter > last_symbol:
        last_symbol = letter

if answer:
    print('YES')
else:
    print('NO')
