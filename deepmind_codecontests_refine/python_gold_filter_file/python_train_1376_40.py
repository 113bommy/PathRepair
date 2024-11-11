for _ in range(int(input())):
    s = input()
    if s.endswith('po'):
        print('FILIPINO')
    elif s.endswith('su'):
        print('JAPANESE')
    else:
        print('KOREAN')
