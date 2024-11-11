def f(c):
    return c in 'aeiou13579'

def main():
    s = input()
    print(sum(1 for c in s if f(c)))

main()
