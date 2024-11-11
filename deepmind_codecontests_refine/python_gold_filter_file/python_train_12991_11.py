ans = {
    3: [
        'aa.',
        '..a',
        '..a'
    ],
    4: [
        'aacd',
        'bbcd',
        'cdaa',
        'cdbb'
    ],
    5: [
        'aabbc',
        'bcc.c',
        'b..ba',
        'c..ba',
        'cddee'
    ],
    6: [
        'aabbcc',
        'bbccdd',
        'a.a.a.',
        'a.a.a.',
        '.a.a.a',
        '.a.a.a'
    ],
    7: [
        'aabbaa.',
        'ccaa..b',
        'aacc..b',
        '....bca',
        '....bca',
        '....cbc',
        '....cbc'
    ]
}
N = int(input())
if N < 8:
    if N in ans:
        for line in ans[N]:
            print(line)
    else:
        print(-1)
else:
    div = N // 4
    for i in range(div-1):
        for line in ans[4]:
            print('.'*(i*4) + line + '.'*(N-(i*4)-4))
    m = (N % 4) + 4
    for line in ans[m]:
        print('.'*(N-m) + line)