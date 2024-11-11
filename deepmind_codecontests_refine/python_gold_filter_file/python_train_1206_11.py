if __name__ == '__main__':
    substr = 'heidi'
    sub_idx = 0
    str_idx = 0

    s = input()
    for i in range(len(s)):
        if s[i] == substr[sub_idx]:
            sub_idx += 1
        if sub_idx == len(substr):
            print('YES')
            exit(0)

    print('NO')