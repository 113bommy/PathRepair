
def main():
    s = input()

    lower = len([c for c in s if c.islower()])
    upper = len(s) - lower

    if upper > lower:
        print(s.upper())
    else:
        print(s.lower())

if __name__ == "__main__":
    main()