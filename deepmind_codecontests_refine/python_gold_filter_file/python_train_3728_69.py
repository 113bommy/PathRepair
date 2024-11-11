import itertools

x, y, z, k = map(int, input().split())
a = list( map(int, input().split()))
b = list( map(int, input().split()))
c = list( map(int, input().split()))

mix_ab= [a_+b_ for a_,b_ in itertools.product(a, b)]
mix_ab.sort(reverse=True)
c.sort(reverse=True)

mix_abc= [ab_+c_ for ab_,c_ in itertools.product(mix_ab[:k], c[:k])]
mix_abc.sort(reverse=True)

print(*mix_abc[:k], sep='\n')