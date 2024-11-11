def get_words():
    word_one = input("").strip()
    word_two = input("").strip()
    return word_one, word_two


def prefix_length(long_word, short_word):
    idx = 0
    while idx < len(short_word):
        if short_word[idx] != long_word[idx]:
            break
        idx += 1
    return idx


def suffix_length(long_word, short_word):
    idx = len(long_word) - 1
    while idx >= 1:
        if short_word[idx - 1] != long_word[idx]:
            break
        idx -= 1
    return len(long_word) - idx - 1


def find_deletions(long_word, short_word):
    prefix_len = prefix_length(long_word, short_word)
    suffix_len = suffix_length(long_word, short_word)
    total = (prefix_len + 1) - (len(long_word) - suffix_len) + 1
    if total < 0:
        print(0)
    else:
        print(total)
        indices = [str(i + len(long_word) - suffix_len) for i in range(0, total)]
        print(" ".join(indices))


def main():
    long_word, short_word = get_words()
    find_deletions(long_word, short_word)


if __name__ == "__main__":
    main()
