import sys


def save_case(c: str, x: str) -> str:
    if x.islower():
        return c
    return c.upper()


def solve(test):
    board1, board2, text = test.split()
    board_map = {
        board1[i]: c
        for i, c in enumerate(board2)
    }
    return ''.join(map(
        lambda x: save_case(board_map.get(x.lower(), x), x),
        text
    ))


def get_input():
    return sys.stdin.read()


def go():
    print(solve(get_input()))

go()