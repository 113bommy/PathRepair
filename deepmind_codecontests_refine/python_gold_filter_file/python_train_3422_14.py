from sys import stdin

def ascii2num(ascii):
    return ord(ascii) - 96

def num2ascii(num):
    return chr(num + 96)

def slide(word,num):
    return ''.join([num2ascii((ascii2num(ascii) - num) % 26 + 1) if ascii != '.' else '.' for ascii in word])

def includekeyword(words):
    for word in words:
        if word in keywords:
            return True
    return False

keywords = ['the', 'this', 'that']

decode = []
for row in stdin:
    words = row.split()
    for num in range(1,27):
        tmp = [slide(word,num) for word in words]
        if includekeyword(tmp):
            decode = tmp
            print(' '.join(decode))
            break