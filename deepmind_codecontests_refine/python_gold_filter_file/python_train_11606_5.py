from math import factorial
from typing import Callable, Iterator, TypeVar, cast

_F = TypeVar("_F", bound=Callable[[], None])
_I = TypeVar("_I", bound=Iterator[int])


def repeater(func: _F) -> _F:
    def wrapper():
        for _ in range(int(input())):
            func()

    return cast(_F, wrapper)


def get_num_input() -> _I:
    return map(int, input().split())


# @repeater
def main() -> None:
    limit: int = int(input()) - 1
    print(factorial(limit * 2) // factorial(limit) ** 2)


if __name__ == "__main__":
    main()
