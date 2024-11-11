
def solve(text):
    '''
    >>> solve('NonZERO')
    5
    >>> solve('this is zero')
    0
    >>> solve('Harbour Space University')
    1
    '''

    l_text = 0
    l_word = 0
    for ch in text:
        if ch in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            l_word += 1
        elif ch in 'abcdefghijklmnopqrstuvwxyz':
            pass
        else:
            l_text = max(l_text, l_word)
            l_word = 0
    l_text = max(l_text, l_word)
    return l_text


if __name__ == '__main__':
    _ = input()
    print(solve(input()))



