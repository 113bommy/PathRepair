n, p1, p2, p3, t1, t2 = map(int, input().split())

aktivnosti = []
for i in range(n):
    l, r = map(int, input().split())
    aktivnosti.append((l, r))

otvet = 0
for i in range(n):
    vremya_raboty = aktivnosti[i][1] - aktivnosti[i][0]
    otvet += vremya_raboty * p1
    if i == n - 1:
        break
    pereryv = aktivnosti[i + 1][0] - aktivnosti[i][1]
    vremeni_v_p1 = min(t1, pereryv)
    otvet += vremeni_v_p1 * p1
    vremeni_v_p2 = min(t2, max(0, pereryv - t1))
    otvet += vremeni_v_p2 * p2
    vremeni_v_p3 = max(0, pereryv - t1 - t2)
    otvet += vremeni_v_p3 * p3 

print(otvet)
