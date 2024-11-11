def main():
    necklace = input()
    n_pearls = necklace.count('o')
    n_links = len(necklace) - n_pearls

    print('YES' if n_pearls == 0 or n_links % n_pearls == 0 else 'NO')


if __name__ == '__main__':
    main()
