# HEY STALKER
hp_y, at_y, df_y = map(int, input().split())
hp_m, at_m, df_m = map(int, input().split())
cst_hp, cst_at, cst_df = map(int, input().split())
ans = 2e18
for ati in range(201):
    for dfi in range(201):
        if ati + at_y > df_m:
            k = hp_m // ((at_y + ati) - df_m)
            if hp_m % ((at_y + ati) - df_m) != 0:
                k += 1
            t = max(0, k*(at_m-df_y-dfi) - hp_y+1)
            cost = cst_hp*t + cst_df*dfi + cst_at*ati
            ans = min(ans, cost)
print(ans)