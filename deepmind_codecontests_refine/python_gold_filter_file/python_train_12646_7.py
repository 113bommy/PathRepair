# coding=utf-8

if __name__ == '__main__':
    n = int(input())
    line = str(input())
    if n >= 26 and len(set(list(line.lower()))) >= 26:
        print('YES')
    else:
        print('NO')
