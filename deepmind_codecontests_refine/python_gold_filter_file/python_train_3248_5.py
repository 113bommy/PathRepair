def main():
    input()
    office, table, res, i = set(), set(), [], -1
    for j, s in enumerate(input().split()):
        if s[0] == '-':
            s = s[1:]
            if s not in office:
                return print('-1')
            office.remove(s)
            if not office:
                res.append(j - i)
                i, table = j, set()
        else:
            if s in table:
                return print('-1')
            office.add(s)
            table.add(s)
    if office:
        return print('-1')
    print(len(res), ' '.join(map(str, res)), sep='\n')


if __name__ == '__main__':
    main()
