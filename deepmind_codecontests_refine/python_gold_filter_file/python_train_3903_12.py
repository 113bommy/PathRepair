if __name__ == "__main__":
    st = list(input().strip())
    ts = st[:]
    if len(st) == 1 and st[0] == '4':
        print(1)
    elif len(st) == 1 and st[0] == '7':
        print(2)
    else:
        for i in range(len(st)):
            if st[i] == '4':
                st[i] = '0'
            else:
                st[i] = '1'
        st = ''.join(st)
        print(2**(len(ts)) - 1 + int(st,2))